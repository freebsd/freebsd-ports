# New ports collection makefile for:	porttools
# Date created:		2003-06-18
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	porttools
PORTVERSION=	0.99
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Tools for testing and submitting port updates and new ports

RUN_DEPENDS=	portlint:${PORTSDIR}/ports-mgmt/portlint \
		cdiff:${PORTSDIR}/textproc/cdiff \
		sudo:${PORTSDIR}/security/sudo

.if !defined(WITHOUT_NEWFILE)
RUN_DEPENDS+=	newfile:${PORTSDIR}/devel/newfile
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-docs
.endif

MAKE_ENV=	DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}"
MAN1=		port.1
MAN5=		porttools.5

.include <bsd.port.mk>
