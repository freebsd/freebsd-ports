PORTNAME=	vmailmgr
PORTVERSION=	0.97
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ GENTOO

MAINTAINER=	mij@bitchx.it
COMMENT=	Virtual domain manager for qmail
WWW=		http://www.vmailmgr.org

LICENSE=	GPLv2+

DEPRECATED=	Last upstream release was in 2005 and upstream points to different site
EXPIRATION_DATE=	2023-08-22

# get python paths (PYTHON_SITELIBDIR) in case we install the python API
USES=			autoreconf gmake perl5 python
USE_CXXSTD=		c++14
USE_PERL5=		build

GNU_CONFIGURE=		yes

BINARY_ALIAS=	python=${PYTHON_CMD}

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		DOCS GDBM PYTHON
OPTIONS_SUB=	yes

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_USES=		localbase
GDBM_CONFIGURE_ON=	--with-vpwtable=gdbm
PYTHON_BROKEN=	Do not support recent python versions
PYTHON_CONFIGURE_ON=	--with-pythonapi=${PYTHON_SITELIBDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
