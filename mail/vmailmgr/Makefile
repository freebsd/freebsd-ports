# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	vmailmgr
PORTVERSION=	0.97
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.vmailmgr.org/current/	\
		http://mirrors.dataloss.nl/vmailmgr.org/current/

MAINTAINER=	mij@bitchx.it
COMMENT=	Virtual domain manager for qmail

MAN1=	checkvpw.1 vauthenticate.1 dumpvuser.1 \
	listvdomain.1 vadduser.1 vchattr.1 vchforwards.1 \
	vdeliver.1 vdeluser.1 vpasswd.1 vpasswds.1 vrehash.1 \
	vsetup.1 vupgrade.1

MAN7=	vmailmgr.7
MAN8=	vmailmgrd.8

# get python paths (PYTHON_SITELIBDIR) in case we install the python API
USES=			gmake perl5
USE_AUTOTOOLS=		autoconf autoheader automake aclocal
USE_PYTHON=		yes
USE_PERL5=		build
AUTOMAKE_ARGS+=		--add-missing -Wno-portability

OPTIONS_DEFINE=		PYTHONLIBS
PYTHONLIBS_DESC=	Install the Python API

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.if ${PORT_OPTIONS:MPYTHONLIB}
CONFIGURE_ARGS+=	--with-pythonapi=${PYTHON_SITELIBDIR}
PLIST_SUB+=		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"
PLIST_SUB+=		PYTHON=""
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

.include <bsd.port.mk>
