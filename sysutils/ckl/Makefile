# New ports collection makefile for:	ckl
# Date created:				1 June 2010
# Whom:					Tomaz Muraus <kami@k5-storitve.net>
#
# $FreeBSD$
#

PORTNAME=	ckl
PORTVERSION=	0.9.1
CATEGORIES=	sysutils net
MASTER_SITES=	http://packages.cloudkick.com/releases/ckl/
DISTNAME=	ckl-${PORTVERSION}

MAINTAINER=	kami@k5-storitve.net
COMMENT=	A command line tool for noting when something was changed on a machine

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_SCONS=	yes
USE_BZIP2=	yes

PORTDOCS=	CHANGES LICENSE NOTICE README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ckl ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/webapp
	(cd ${WRKSRC}/webapp/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/webapp)
.endif
	${INSTALL_DATA} ${PATCHDIR}/cloudkick.conf.example ${PREFIX}/etc/cloudkick.conf.sample
	@if [ ! -f ${PREFIX}/etc/cloudkick.conf ]; then \
	${INSTALL_DATA} -p ${PREFIX}/etc/cloudkick.conf.sample ${PREFIX}/etc/cloudkick.conf ; \
	fi

.include <bsd.port.mk>
