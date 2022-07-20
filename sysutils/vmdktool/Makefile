PORTNAME=	vmdktool
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.Awfulhak.org/vmdktool/ \
		ftp://ftp.Awfulhak.org/pub/vmdktool/ \
		http://people.FreeBSD.org/~brian/vmdktool/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Convert VMDK files to/from raw disk images

LICENSE=	BSD2CLAUSE

USES=		perl5
# We need the prove utility from Perl 5.
USE_PERL5=	test

PLIST_FILES=	bin/vmdktool \
		man/man8/vmdktool.8.gz

ALL_TARGET=	vmdktool
TEST_TARGET=	test

.include <bsd.port.mk>
