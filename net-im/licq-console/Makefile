# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ncurses-based console plugin for Licq

LIB_DEPENDS=	cdk.5:${PORTSDIR}/devel/cdk \
		boost_regex.4:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	net-im/licq
CPPFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/licq/licq_console.la \
		lib/licq/licq_console.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		gp-relative relocation against dynamic symbol
.endif

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

post-patch:
	${REINPLACE_CMD} -e "s|/usr/local/|${LOCALBASE}/|g" \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
