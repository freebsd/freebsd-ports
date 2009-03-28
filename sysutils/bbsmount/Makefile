# New ports collection makefile for:	bbsmount
# Date created:				11 October 2003
# Whom:				Eric J. Christeson <ejc@crackpot.org>
#
# $FreeBSD$
#

PORTNAME=	bbsmount
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://phoenix.inf.upol.cz/~jezberam/bbsmount/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical disk mounter for the Blackbox slit

USE_XORG=	x11 ice xpm xi
GNU_CONFIGURE=	yes
USE_GCC=	2.95
PORTDOCS=	README BUGS NEWS AUTHORS ChangeLog

MAN1=		bbsmount.1

DEPRECATED=	unmaintained, does not work with current versions of GCC, needs gcc295 which has been failing to build for months
EXPIRATION_DATE=2009-04-28

post-patch:
	@${REINPLACE_CMD} -e 's|-O[012]||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|SUBDIRS = data|SUBDIRS =|' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Installing documentation"
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/share/bbtools
	@${MKDIR} ${EXAMPLESDIR}
	if [ ! -e ${PREFIX}/share/bbtools/bbsmount.bb ]; then \
		${CP} -p ${WRKSRC}/data/bbsmount.bb \
		${PREFIX}/share/bbtools/bbsmount.bb; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/data/bbsmount.bb ${PREFIX}/share/bbtools/bbsmount.bb-sample
	@${INSTALL_DATA} ${WRKSRC}/data/bbsmount.bb.ex ${EXAMPLESDIR}/bbsmount.bb.ex

.include <bsd.port.mk>
