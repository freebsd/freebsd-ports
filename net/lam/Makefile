# New ports collection makefile for:		lam
# Date created:					Aug 21 2001
# Whom:						bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	lam
PORTVERSION=	6.5.9
CATEGORIES=	net parallel
MASTER_SITES=	http://www.lam-mpi.org/download/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Local Area Multicomputer MPI implementation

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-rsh=ssh

CONFLICTS=	lam-7.*

DEPRECATED=	to be replaced by net/lam7, please use this port instead
EXPIRATION_DATE=2006-08-18

.include "files/manpages"

.include <bsd.port.mk>
