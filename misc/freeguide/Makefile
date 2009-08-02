# New ports collection makefile for:	freeguide
# Date Created:		27 October 2005
# Whom:			Stephen Hurd <shurd@sasktel.net>
#
# $FreeBSD$
# $Carpetsmoker: ports/misc/freeguide/Makefile,v 1.1 2007/10/12 12:28:45 carpetsmoker Exp $
#

PORTNAME=	freeguide
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	misc java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freeguide-tv

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive TV guide which will create personalized TV listings

RUN_DEPENDS=	tv_cat:${PORTSDIR}/textproc/p5-xmltv

USE_JAVA=	yes
USE_JIKES=	no
JAVA_VERSION=	1.4+
USE_ANT=	yes
MANCOMPRESSED=	yes
MAN1=		freeguide.1

MAKE_ARGS=	-Dinstall_share_dir=${PREFIX}/share \
		-Dinstall_man1_dir=${MAN1PREFIX} \
		-Dinstall_java_bin=${JAVA} \
		-Dinstall_real_doc_dir=${DOCSDIR} \
		-Dinstall_bin_dir=${PREFIX}/bin \
		-Dinstall_doc_dir=${DOCSDIR} \
		-Dinstall_java_share_dir=${JAVASHAREDIR} \
		-Dinstall_jar_dir=${JAVAJARDIR}/freeguide
INSTALL_TARGET=	install-linux

post-patch:
	@${REINPLACE_CMD} 's|__ANT_INSTALL_DIRECTORY__|${JAVAJARDIR}/freeguide|; \
		s|=java|=${JAVA}|;' \
		${WRKSRC}/install/linux/freeguide
	@${REINPLACE_CMD} 's|install_share_dir}/man|install_man1_dir}/man|g' \
		${WRKSRC}/ant/install-linux.xml

do-install:
	@(cd ${BUILD_WRKSRC}; \
		${ANT} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
