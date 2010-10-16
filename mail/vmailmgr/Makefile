# New ports collection makefile for:	vmailmgr
# Date created:			24 October 2007
# Whom:				Mij <mij@bitchx.it>
#
# $FreeBSD$
#

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
USE_GMAKE=			yes
USE_AUTOTOOLS=		autoconf:268 autoheader:268 automake:111 aclocal:111
USE_PYTHON=			yes
USE_PERL5_BUILD=	yes
AUTOMAKE_ARGS+=		--add-missing -Wno-portability
MAKE_JOBS_SAFE=		yes

OPTIONS=		PYTHONLIB	"Install the Python API" Off

.include <bsd.port.pre.mk>

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.if defined(WITH_PYTHONLIB)
CONFIGURE_ARGS+=	--with-pythonapi=${PYTHON_SITELIBDIR}
PLIST_SUB+=		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"
PLIST_SUB+=		PYTHON=""
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

.include <bsd.port.post.mk>
