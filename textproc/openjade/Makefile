# New ports collection makefile for:	OpenJade
# Date created:		May 19, 2000
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	openjade
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kuriyama@FreeBSD.org

USE_GMAKE=	YES
USE_LIBTOOL=	YES
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade
INSTALLS_SHLIB=	yes

pre-install:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-install:
	@${MKDIR} ${PREFIX}/share/sgml/openjade
	@${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/openjade

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
# The following sed does not reproduce the awk result. Odd.
# ${SED} -e 's/-m[0-9a-zA-Z]+(=[0-9a-zA-Z]*)?//g' -e 's/-O[s2-9]+//g'
CFLAGS!=	${ECHO} "${CFLAGS}" | ${AWK} 'BEGIN \
			{ RS="-m[0-9a-zA-Z]+(=[0-9a-zA-Z]*)?|-O[s2-9]+" ; \
				ORS="" } ; \
			{ if (RT == "") { print $0 } else print }'

.include <bsd.port.post.mk>
