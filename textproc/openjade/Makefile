# New ports collection makefile for:	OpenJade
# Date created:		May 19, 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	openjade
PORTVERSION=	1.3.2
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

LIB_DEPENDS=	osp.3:${PORTSDIR}/textproc/opensp
RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_GMAKE=	YES
USE_INC_LIBTOOL_VER=13
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade
INSTALLS_SHLIB=	yes
PLIST_SUB=	XMLCATMGR=${XMLCATMGR}
PLIST_SUB+=	CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/openjade
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG openjade/catalog

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

.include <bsd.port.post.mk>
