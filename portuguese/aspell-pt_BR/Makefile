PORTNAME=	aspell
SPELLVERSION=	6-pt_BR-20131030-12-0
CATEGORIES=	portuguese textproc
PKGNAMEPREFIX?=	pt_BR-

MAINTAINER=	office@FreeBSD.org
COMMENT=	Aspell Brazilian Portuguese dictionary
WWW=		https://pt-br.libreoffice.org/projetos/projetos-brasileiros/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/Copyright

PORTSCOUT=	skipv:6-pt_BR-20070206,6-pt_BR-20070411-0,6-pt_BR-20080221-0,6-pt_BR-20080221-1,6-pt_BR-20080707-0

NO_ARCH=	yes

DICT=		pt_BR

.include "${.CURDIR}/../../textproc/aspell/Makefile.inc"
.include <bsd.port.post.mk>
