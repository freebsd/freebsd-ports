# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	exslt
PORTVERSION=	2003.10.24
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.exslt.org/
DISTNAME=	all-${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Community initiative extensions to XSLT

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

DATAFILES=	base.css date dyn exsl func howto.html index.html math random regexp set str
PORTDATA=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
