# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=		simplehtmldom
DISTVERSION=		1.5
PORTEPOCH=		1
CATEGORIES=		textproc www
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME=		${PORTNAME}_${DISTVERSION:S/./_/g}

MAINTAINER=		joehorn@gmail.com
COMMENT=		PHP Simple HTML DOM Parser

WRKSRC=			${WRKDIR}

USES=		zip
NO_BUILD=		YES

USE_PHP=		pcre

DEFAULT_PHP_VER=	5

SUB_FILES+=		pkg-message
SUB_LIST+=		DATADIR=${DATADIR} PREFIX=${PREFIX}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	@${FIND} ${WRKSRC} -name .svn -type d | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${DATADIR} ${DATADIR}/app ${DATADIR}/testcase
	@${ECHO_CMD} "=> Installing programs to ${DATADIR}"
	@${INSTALL} -c -m 644 ${WRKSRC}/simple_html_dom.php ${DATADIR}
	@${INSTALL} -c -m 644 ${WRKSRC}/change_log.txt ${DATADIR}
	@cd ${WRKSRC}/app && ${FIND} . -type d \
		-exec ${MKDIR} ${DATADIR}/app/{} \;
	@cd ${WRKSRC}/app && ${FIND} . -type f \
		-exec ${INSTALL} -c -m 644 "{}" "${DATADIR}/app/{}" \;
	@cd ${WRKSRC}/testcase && ${FIND} . -type d \
		-exec ${MKDIR} ${DATADIR}/testcase/{} \;
	@cd ${WRKSRC}/testcase && ${FIND} . -type f \
		-exec ${INSTALL} -c -m 644 "{}" "${DATADIR}/testcase/{}" \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${ECHO_CMD} "=> Installing manuals to ${DOCSDIR}"
	@cd ${WRKSRC}/manual && ${FIND} . -type d \
		-exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/manual && ${FIND} . -type f \
		-exec ${INSTALL} -c -m 644 "{}" "${DOCSDIR}/{}" \;
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${ECHO_CMD} "=> Installing examples to ${EXAMPLESDIR}"
	@cd ${WRKSRC}/example && ${FIND} . -type d \
		-exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	@cd ${WRKSRC}/example && ${FIND} . -type f \
		-exec ${INSTALL} -c -m 644 "{}" "${EXAMPLESDIR}/{}" \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
