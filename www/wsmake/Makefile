# New ports collection makefile for: wsmake
# Date created:        31 May, 2002
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wsmake
PORTVERSION=	0.6.4
CATEGORIES=	www
MASTER_SITES=	http://www.wsmake.org/dwnlds/stable/ \
		http://www.wsmake.org/docs/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} examples.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for production and maintenance of web sites

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

.if !defined(NOPORTDOCS)
DISTFILES+=	user-manual-html.tar.gz
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,void\*,char\*,g' ${WRKSRC}/libwsmake/wsUtil.cpp

# Install examples and optional documentation.
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${EXAMPLESDIR} && \
		 ${TAR} -xzf ${_DISTDIR}/examples.tar.gz --exclude '*/CVS/*'
.for ex in 1 2 3 4 5 6 7 8 9 10 11 12 13
	@${MV} ${EXAMPLESDIR}/examples/ex${ex} ${EXAMPLESDIR}
.endfor
	@${RM} -rf ${EXAMPLESDIR}/examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${DOCSDIR} && \
		${TAR} -xzf ${_DISTDIR}/user-manual-html.tar.gz
	${LN} ${DOCSDIR}/user-manual/book1.html ${DOCSDIR}/user-manual/index.html
.endif

.include <bsd.port.post.mk>
