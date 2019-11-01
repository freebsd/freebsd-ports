# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	vmailmgr
PORTVERSION=	0.97
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ GENTOO

MAINTAINER=	mij@bitchx.it
COMMENT=	Virtual domain manager for qmail

LICENSE=	GPLv2+

# get python paths (PYTHON_SITELIBDIR) in case we install the python API
USES=			autoreconf gmake perl5 python
GNU_CONFIGURE=		yes
USE_PERL5=		build

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		DOCS GDBM PYTHONLIBS
PYTHONLIBS_DESC=	Install the Python API

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_USES=		localbase
GDBM_CONFIGURE_ON=	--with-vpwtable=gdbm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHONLIB}
CONFIGURE_ARGS+=	--with-pythonapi=${PYTHON_SITELIBDIR}
PLIST_SUB+=		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"
PLIST_SUB+=		PYTHON=""
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
