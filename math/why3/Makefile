# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	why3
PORTVERSION=	0.83
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/33490/ \
		http://pkgs.fedoraproject.org/repo/pkgs/why3/${FEDORA}/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Deductive program verification platform

LICENSE=	LGPL21

CONFLICT_INSTALL= why3-gpl-*

FEDORA=		${DISTNAME}${EXTRACT_SUFX}/35f99e5f64939e50ea57f641ba2073ec
ALL_TARGET=	all byte
HAS_MANUAL=	yes

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.mk>
