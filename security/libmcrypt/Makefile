# New ports collection makefile for:	mcrypt
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmcrypt
PORTVERSION=	2.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/libmcrypt/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	ltdl.1:${PORTSDIR}/devel/libtool

RESTRICTED=	"yes - cryptography"

USE_PERL5=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN3=		mcrypt.3

post-extract:
# so we need not audit the configure scripts
	${FIND} ${WRKSRC} -name configure -exec ${RM} -f \{\} \;

pre-patch:
	@${FIND} ${WRKSRC}/modules -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|#ifdef USE_LTDL|#if defined(USE_LTDL) && !defined(__FreeBSD__)|g'

post-patch:
	@cd ${WRKSRC}/libltdl && ${LOCALBASE}/bin/autoconf

pre-configure:
# because we removed the configure scripts
	cd ${WRKSRC} && autoconf

.include <bsd.port.mk>
