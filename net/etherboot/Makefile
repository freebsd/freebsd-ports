
DISTNAME=	etherboot-4.1
PKGNAME=	etherboot-4.1
CATEGORIES=	net
DISTFILES=	etherboot-4.1pre9.tar.bz2
MASTER_SITES=   http://www.slug.org.au/etherboot/

MAINTAINER=	ambrisko@whistle.com

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2 \
		${PREFIX}/bin/as86:${PORTSDIR}/devel/bcc

EXTRACT_CMD=		bzip2 -d < 
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| tar xf -

USE_GMAKE=1	# note uses is from emulation package
WRKSRC=		${WRKDIR}/${DISTNAME}/src-32

.include <bsd.port.mk>
