PORTNAME=	uctodata
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Datafiles for the tokenizer 'ucto'
WWW=		https://languagemachines.github.io/ucto/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	LanguageMachines

NO_ARCH=	yes

DATADIR=	${PREFIX}/share/ucto

.include <bsd.port.mk>
