PORTNAME=	fidogate
PORTVERSION=	4.4.10
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF \
		ftp://ftp.fu-berlin.de/unix/news/fidogate/
PKGNAMESUFFIX?=	4${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fido-Internet Gateway and Tosser
WWW=		http://fidogate.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	fidogate-5*
MAKE_JOBS_UNSAFE=	yes

USES=		gmake perl5
MAKE_ARGS=	OWNER=${UID} GROUP=$$(id -g)
PLIST_SUB=	FIDOGATE_USER=${FIDOGATE_RUNAS}

FIXDEST=	. doc doc/gatebau doc/html scripts/areas \
		scripts/maintenance scripts/misc scripts/nodelist \
		scripts/outbound scripts/run scripts/www src/areafix \
		src/charset src/ffx src/gate src/tick src/toss src/util
DOCLIST=	fidogate.texi fidogate.txt gatebau94.txt kludge-rfc.doc \
		msgid.doc qmail.txt texinfo.tex dirs.html index.html \
		template.html fido howto misc rfc gatebau/msgid.sgml \
		gatebau/msgid.tex gatebau/msgid.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

FIDOGATE_RUNAS?=	news

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's| .(PREFIX)| $$(DESTDIR)$$(PREFIX)|g' \
		${FIXDEST:S,$,/Makefile,S,^,${WRKSRC}/,}

pre-configure:
	${TOUCH} ${WRKSRC}/doc/fidogate.info
	${RM} ${WRKSRC}/doc/fidogate.info-?
	${RM} ${WRKSRC}/doc/fidogate.txt
	${REINPLACE_CMD} -e "s|[.]info-|.info|" ${WRKSRC}/doc/Makefile
	${REINPLACE_CMD} -e "s|.{PREFIX}|${PREFIX}|g" \
		 -e "s|.{LOCALBASE}|${LOCALBASE}|g" \
		 -e "s|^CC|#CC|" ${WRKSRC}/config.make
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e "s|test doc|test|" \
		-e "s|cp ANNOUNCE|#cp ANNOUNCE|" \
		 ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|run www|run|" ${WRKSRC}/scripts/Makefile
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/fidogate

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html \
		${STAGEDIR}${DOCSDIR}/info \
		${STAGEDIR}${DOCSDIR}/fido \
		${STAGEDIR}${DOCSDIR}/howto \
		${STAGEDIR}${DOCSDIR}/misc \
		${STAGEDIR}${DOCSDIR}/gatebau

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - ${DOCLIST} | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -

.include <bsd.port.mk>
