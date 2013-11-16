# $FreeBSD$

PORTNAME=	fidogate
PORTVERSION=	4.4.10
CATEGORIES=	news mail
MASTER_SITES=	SF \
		ftp://ftp.fu-berlin.de/unix/news/fidogate/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fido-Internet Gateway and Tosser

MAKE_JOBS_UNSAFE=	yes
NEED_ROOT=	yes

USES=		gmake perl5

FIXDEST=	. doc doc/gatebau doc/html scripts/areas \
		scripts/maintenance scripts/misc scripts/nodelist \
		scripts/outbound scripts/run scripts/www src/areafix \
		src/charset src/ffx src/gate src/tick src/toss src/util
DOCLIST=	fidogate.texi fidogate.txt gatebau94.txt kludge-rfc.doc \
		msgid.doc qmail.txt texinfo.tex dirs.html index.html \
		template.html fido howto misc rfc gatebau/msgid.sgml \
		gatebau/msgid.tex gatebau/msgid.txt

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's| .(PREFIX)| $$(DESTDIR)$$(PREFIX)|g' \
		${FIXDEST:S,$,/Makefile,S,^,${WRKSRC}/,}

pre-configure:
	${TOUCH} ${WRKSRC}/doc/fidogate.info
	${RM} -f ${WRKSRC}/doc/fidogate.info-?
	${RM} -f ${WRKSRC}/doc/fidogate.txt
	${REINPLACE_CMD} -e "s|[.]info-|.info|" ${WRKSRC}/doc/Makefile
	${REINPLACE_CMD} -e "s|.{PREFIX}|${PREFIX}|g" \
		 -e "s|.{LOCALBASE}|${LOCALBASE}|g" \
		 -e "s|^CC|#CC|" ${WRKSRC}/config.make
.if defined(FIDOGATE_RUNAS)
	${REINPLACE_CMD} -e "s|OWNER.*= news|OWNER		= ${FIDOGATE_RUNAS}|" \
		${WRKSRC}/config.make
.endif
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e "s|test doc|test|" \
		-e "s|cp ANNOUNCE|#cp ANNOUNCE|" \
		 ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|run www|run|" ${WRKSRC}/scripts/Makefile
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/fidogate
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html \
		${STAGEDIR}${DOCSDIR}/info \
		${STAGEDIR}${DOCSDIR}/fido \
		${STAGEDIR}${DOCSDIR}/howto \
		${STAGEDIR}${DOCSDIR}/misc \
		${STAGEDIR}${DOCSDIR}/gatebau
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - ${DOCLIST} | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | ${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
