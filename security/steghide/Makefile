# New ports collection makefile for:	steghide
# Date created:				26 February 2001
# Whom:					RaRa Rasputin <rasputin@submonkey.net>
#
# $FreeBSD$
#

PORTNAME=	steghide
PORTVERSION=	0.4.6.b
CATEGORIES=	security
MASTER_SITES=	http://steghide.sourceforge.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	freebsdports@arved.de

LIB_DEPENDS=	mcrypt.7:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash \
		intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
USE_REINPLACE=	yes

MAN1=		steghide.1

post-patch:
.ifdef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|install-data-am\: install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
