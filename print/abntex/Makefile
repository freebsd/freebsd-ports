# New ports collection makefile for:	abntex
# Date created:	Tue Sep 17 22:08:35 BRT 2002
# Whom:		Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	abntex
PORTVERSION=	0.5
CATEGORIES=	print
MASTER_SITES=	http://download.codigolivre.org.br/abntex/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hmendes@brturbo.com

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
#
SORT?=		/usr/bin/sort

do-install:
# extract into staging area
	@cd ${WRKDIR} && ${TAR} -xf ${WRKSRC}/abntex-texmf-${PORTVERSION}.tar
# prepare information about installation
	@cd ${WRKDIR} && ${FIND} texmf -type f > ${WRKDIR}/files && \
		${FIND} texmf -type d | ${SORT} > ${WRKDIR}/dirs
# create dirs
	@for dir in `${CAT} ${WRKDIR}/dirs`; do \
		${MKDIR} ${PREFIX}/share/$${dir} ; \
	done
# install files
	@for file in `${CAT} ${WRKDIR}/files`; do \
		${INSTALL_DATA} ${WRKDIR}/$${file} ${PREFIX}/share/$${file} ; \
	done
# inform tex about installation
	@${LOCALBASE}/bin/texhash

.include <bsd.port.mk>
