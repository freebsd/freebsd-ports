# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	librra
PORTVERSION=	0.14
CATEGORIES?=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}
PKGNAMEPREFIX?=	synce-

MAINTAINER=	webmaster@kibab.com
COMMENT?=	Remote Replication Agent Connection protocol library

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir
RUN_DEPENDS+=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir

OPTIONS_DEFINE=	TOOLS RECURR
OPTIONS_DEFAULT=	TOOLS
TOOLS_DESC=	Build with minor rra command line tools
RECURR_DESC=	Enable experimential recurrence support

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig iconv
CONFIGURE_ARGS+=	--with-libsynce="${LOCALBASE}" \
			--with-libmimedir="${LOCALBASE}"

.include <bsd.port.options.mk>

.if defined(RRA_SLAVE) && ${RRA_SLAVE} == "pythonb"
# If we're building python bindings, omit building tools
CONFIGURE_ARGS+=	--enable-python-bindings --disable-minor-tools
.else
# Not building bindings
MAN1=	synce-matchmaker.1
CONFIGURE_ARGS+=	--disable-python-bindings
.if ! ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	TOOLS="@comment "
CONFIGURE_ARGS+=	--disable-minor-tools
.else
MAN1+=		rra-appointment-from-vevent.1 \
		rra-appointment-to-vevent.1 rra-contact-from-vcard.1 \
		rra-contact-to-vcard.1 rra-decode.1 \
		rra-delete.1 rra-get-data.1 \
		rra-get-ids.1 rra-get-types.1 \
	        rra-get-recurring-appointments.1 rra-put-data.1 \
	        rra-subscribe.1 rra-task-from-vtodo.1 \
	        rra-task-to-vtodo.1 rra-timezone.1
PLIST_SUB+=	TOOLS=""
.endif

.if ${PORT_OPTIONS:MRECURR}
CONFIGURE_ARGS+=	--enable-recurrence
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
