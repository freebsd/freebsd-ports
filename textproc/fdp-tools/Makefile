# New ports collection makefile for:	fdp-tools
# Date created:				25 July 2000
# Whom:					ue@nathan.ruhr.de
#
# $FreeBSD$
#

PORTNAME=	fdp-tools
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.ruhr.de/home/nathan/FreeBSD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of small utilities for the FreeBSD Documentation Projekt

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

MAN1=		makemanent.1 sortmanent.1 slashexpand.1 suppe.1
TOOLS=		makemanent sortmanent slashexpand suppe

do-install:
	cd ${WRKDIR} && \
	${INSTALL_SCRIPT} ${TOOLS} ${PREFIX}/bin &&\
	${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
