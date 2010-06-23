# New ports collection makefile for:	hevea
# Date created:		November 28 1999
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	hevea
PORTVERSION=	1.10
CATEGORIES=	textproc
MASTER_SITES=	http://para.inria.fr/~maranget/hevea/distri/ \
		ftp://ftp.inria.fr/INRIA/moscova/hevea/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-${PORTVERSION}-manual.pdf \
		${PORTNAME}-${PORTVERSION}-manual.ps.gz \
		${PORTNAME}-${PORTVERSION}-manual.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Convert LaTeX to HTML

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

PLIST_SUB=	HEVEAVERSION=${PORTVERSION}

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/hevea
	@${STRIP_CMD} ${PREFIX}/bin/hacha
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.pdf ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.ps.gz ${PREFIX}/share/doc/hevea
	(cd ${PREFIX}/share/doc/hevea; ${TAR} xvfz ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.tar.gz)
	(cd ${PREFIX}/share/doc/hevea; ${GUNZIP_CMD} ${PORTNAME}-${PORTVERSION}-manual.ps.gz)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/hevea
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
