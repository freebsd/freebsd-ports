PORTNAME=	aspell
SPELLVERSION=	6-pt_PT-20190329-1-0
PORTEPOCH=	1
CATEGORIES=	portuguese textproc
PKGNAMEPREFIX?=	pt_PT-

MAINTAINER=	office@FreeBSD.org
COMMENT=	Aspell Portuguese dictionary
WWW=		https://natura.di.uminho.pt/wiki/doku.php?id=dicionarios:main#aspell

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Copyright

PORTSCOUT=	skipv:6-pt_PT-20070206-0

NO_ARCH=	yes

DICT=		pt_PT

.include "${.CURDIR}/../../textproc/aspell/Makefile.inc"
.include <bsd.port.post.mk>
