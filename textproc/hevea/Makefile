# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	hevea
PORTVERSION=	2.09
CATEGORIES=	textproc
MASTER_SITES=	http://para.inria.fr/~maranget/hevea/distri/ \
		ftp://ftp.inria.fr/INRIA/moscova/hevea/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Convert LaTeX to HTML

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

PLIST_SUB=	HEVEAVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-${PORTVERSION}-manual.pdf \
		${PORTNAME}-${PORTVERSION}-manual.ps.gz \
		${PORTNAME}-${PORTVERSION}-manual.tar.gz
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^PREFIX=/s|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/hevea
	@${STRIP_CMD} ${PREFIX}/bin/hacha
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.pdf ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.ps.gz ${PREFIX}/share/doc/hevea
	(cd ${PREFIX}/share/doc/hevea; ${TAR} xvfz ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.tar.gz)
	(cd ${PREFIX}/share/doc/hevea; ${GUNZIP_CMD} ${PORTNAME}-${PORTVERSION}-manual.ps.gz)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/hevea
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
