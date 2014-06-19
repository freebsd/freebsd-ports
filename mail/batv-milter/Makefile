# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	batv-milter
PORTVERSION=	0.5.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A milter for BATV (Bounce Address Tag Validation)

USE_RC_SUBR=	milter-batv
USE_OPENSSL=	TRUE

WCONF=		${WRKSRC}/devtools/Site
PLIST_FILES=	bin/batv-filter man/man8/batv-filter.8.gz
PORTDOCS=	INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		draft-levine-smtp-batv-01.txt

SITE=		${FILESDIR}/site.config.m4
SITE_SUB=	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%OPENSSLINC%%|${OPENSSLINC}|g" \
		-e "s|%%OPENSSLLIB%%|${OPENSSLLIB}|g"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_DEBUG)
SITE_SUB+=	-e '\|confOPTIMIZE.*-g|s/^dnl //g'
.endif

pre-configure:
	${SED} ${SITE_SUB} -e '\|^dnl |d' -e '/^dnl$$/d' \
		${SITE} > ${WCONF}/site.config.m4

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/batv-filter
.endif
	@${RM} -f ${MANPREFIX}/man/cat8/batv-filter.8 ${MANPREFIX}/man/cat8/batv-filter.8.gz
	${INSTALL_MAN} ${WRKSRC}/*/batv-filter.8 ${STAGEDIR}${MANPREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
