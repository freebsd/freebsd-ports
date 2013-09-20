# Created by: rantapaa@uswest.net
# $FreeBSD$

PORTNAME=	psmisc
PORTVERSION=	22.16
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Port of the Linux pstree, killall, and pidof commands

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

CONFLICTS=	pidof-[0-9]* pstree-2.[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS_DEFINE=	NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

MAN1=		killall.1 pstree.1

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^#define COMM_LEN / s|16|254|' ${WRKSRC}/src/comm.h

post-install:
	@${LN} -fs ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include <bsd.port.mk>
