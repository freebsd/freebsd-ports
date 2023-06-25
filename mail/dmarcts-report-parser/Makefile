PORTNAME=	dmarcts-report-parser
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Perl based tool to parse DMARC reports

LICENSE=	GPLv3

RUN_DEPENDS=	\
	p5-File-MimeInfo>=0:devel/p5-File-MimeInfo	\
	p5-Mail-IMAPClient>=0:mail/p5-Mail-IMAPClient	\
	p5-MIME-Tools>=0:mail/p5-MIME-Tools		\
	p5-XML-Simple>=0:textproc/p5-XML-Simple		\
	p5-DBI>=0:databases/p5-DBI			\
	p5-Socket6>=0:net/p5-Socket6			\
	p5-PerlIO-gzip>=0:archivers/p5-PerlIO-gzip	\
	p5-Mail-Mbox-MessageParser>=0:mail/p5-Mail-Mbox-MessageParser

USES=		perl5 shebangfix
SHEBANG_FILES=	*.pl
SUB_FILES=	667.dmarcts-report-parser
USE_GITHUB=	yes
GH_ACCOUNT=	techsneeze
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} \
		's,%%PREFIX%%,${PREFIX},g;s,%%DATADIR%%,${DATADIR},g' \
		${WRKSRC}/dmarcts-report-parser.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dmarcts-report-parser.pl \
		${STAGEDIR}${PREFIX}/bin/dmarcts-report-parser.pl
	${INSTALL_DATA} ${WRKSRC}/dmarcts-report-parser.conf.sample \
		${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dbx_*.pl ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/667.dmarcts-report-parser \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.mk>
