# New ports collection makefile for:	maradns
# Date created:				26 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	maradns
PORTVERSION=	0.9.01
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
MAKE_ENV=	FLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

MAN1=	askmara.1 getzone.1
MAN8=	maradns.8 zoneserver.8

DOCS=	../TODO.0.9.00 ../TODO.done ../TODO.first ../TODO.second \
	../changelog.html ../old.changelog example_csv1 example_mararc \
	faq.txt es/00Quickstart.es detailed/0QuickStart \
	doc-fr/0QuickStart.fr doc-fr/faq-fr.txt
DDOCS=	RFC1035.compliance cache.poison.protection csv1.format \
	example_full_mararc faq.html firewall.configuration \
	handling.compression how.to.support.sql mararc.format \
	multiple.qdcount recursive-case-insensitive recursive.algorithm \
	resolution.algorithm rtest.output www.monty.de

post-patch:
	@find ${WRKSRC} -type f | xargs ${PERL} -pi -e \
		's|/etc/mara|${PREFIX}/etc/mara|g'
	@find ${WRKSRC} -name '*Makefile*' | xargs ${PERL} -pi -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/getzone ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/zoneserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/example_mararc ${PREFIX}/etc/mararc.sample
	${INSTALL_MAN} ${WRKSRC}/doc/man/askmara.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/getzone.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/maradns.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/man/zoneserver.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/detailed
.for file in ${DDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/detailed/${file} ${DOCSDIR}/detailed
.endfor
	@${MKDIR} ${DOCSDIR}/detailed/spammers
	${INSTALL_DATA} ${WRKSRC}/doc/detailed/spammers/*.* \
		${DOCSDIR}/detailed/spammers
	@${MKDIR} ${DOCSDIR}/detailed/spammers/hiddenonline
	${INSTALL_DATA} ${WRKSRC}/doc/detailed/spammers/hiddenonline/*.* \
		${DOCSDIR}/detailed/spammers/hiddenonline
	@${MKDIR} ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.* ${DOCSDIR}/examples
	@${MKDIR} ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/*.* ${DOCSDIR}/tutorial
.endif

.include <bsd.port.mk>
