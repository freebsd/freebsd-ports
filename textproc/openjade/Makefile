# New ports collection makefile for:	OpenJade
# Date created:		May 19, 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	openjade
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_GMAKE=	YES
USE_LIBTOOL=	YES
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade
INSTALLS_SHLIB=	yes
PLIST_SUB=	MKCATALOG=${MKCATALOG}

MKCATALOG=	${PREFIX}/sbin/mkcatalog

pre-install:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-install:
	@${MKDIR} ${PREFIX}/share/sgml/openjade
	@${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/openjade
	@${MKCATALOG} -q install openjade

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CFLAGS!=	${ECHO} "${CFLAGS}" | ${SED} -E -e 's/-m[0-9a-zA-Z]+(=[0-9a-zA-Z]*)?//g' \
			-e 's/-O[s2-9]+//g'

.include <bsd.port.post.mk>
