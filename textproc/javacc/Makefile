# Ports collection makefile for:	JavaCC
# Date Created:				6 May 2002
# Whom:					Andy Gerweck <gerweck@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	javacc
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	textproc java devel
MASTER_SITES=	https://javacc.dev.java.net/files/documents/17/26783/
DISTNAME=	${PORTNAME}-${PORTVERSION}src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java parser generator and lexical analyzer

# Depended on by www/commonist
DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-10-31

USE_JAVA=	yes
USE_ANT=	yes
DISABLE_SIZE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@for f in "${WRKSRC}/bin/j*"; do \
		${REINPLACE_CMD} -e 's:`dirname \$$0`/lib:${JAVAJARDIR}:' $$f; \
	done

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/lib/javacc.jar ${JAVAJARDIR}
	(cd ${WRKSRC}/bin/ && ${INSTALL_SCRIPT} javacc jjdoc jjtree ${PREFIX}/bin/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
