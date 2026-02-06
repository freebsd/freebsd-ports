PORTNAME=	uw-ttyp0
DISTVERSION=	2.1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Monospaced bitmap fonts for X11
WWW=		https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/

LICENSE=		MIT TTYP0
LICENSE_COMB=		multi
LICENSE_NAME_TTYP0=	ttyp0 License
LICENSE_FILE_TTYP0=	${WRKSRC}/LICENSE
LICENSE_PERMS_TTYP0=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bdfresize:x11-fonts/bdfresize \
		bdftopcf:x11-fonts/bdftopcf \
		fonttosfnt:x11-fonts/fonttosfnt

USES=		fonts gmake perl5
USE_PERL5=	build

HAS_CONFIGURE=	yes

# Passing --prefix and --pcfdir to the configure script does not work: it is a
# homebrewed script that relies on features only present in expr(1) from GNU
# coreutils.
MAKE_ARGS=	PREFIX=${PREFIX} PCFDIR=${FONTSDIR} GEN_CONS_FREEBSD_VT=1

NO_ARCH=	yes

.include <bsd.port.mk>
