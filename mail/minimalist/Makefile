# Created by: gmarco@scotty.masternet.it
# $FreeBSD$

PORTNAME=	minimalist
PORTVERSION=	2.5.3
CATEGORIES=	mail
MASTER_SITES=	http://www.mml.org.ua/LIST/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Minimalistic mailing list manager

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes
SUB_FILES=	pkg-message
SHEBANG_FILES=	minimalist.pl contrib/minimalist_request.pl

post-patch:
	${REINPLACE_CMD} -e 's,--fqdn,,' ${WRKSRC}/minimalist.conf-sample
	${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/contrib/minimalist_request.pl
	${REINPLACE_CMD} \
		-e 's,/usr/local/sbin,${PREFIX}/bin,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/docs/README \
		${WRKSRC}/contrib/minimalist_request.pl \
		${WRKSRC}/docs/virtual-domains.txt \
		${WRKSRC}/docs/FAQ/sendmail.smrsh \
		${WRKSRC}/minimalist.pl

do-install:
	@${RM} ${WRKSRC}/docs/FAQ/sendmail.smrsh.bak
	${MKDIR} \
		${STAGEDIR}${PREFIX}/share/minimalist/FAQ \
		${STAGEDIR}${PREFIX}/share/minimalist/sample
	${INSTALL_SCRIPT} \
		${WRKSRC}/minimalist.pl \
		${WRKSRC}/contrib/minimalist_request.pl \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample \
		${STAGEDIR}${PREFIX}/etc/
	${INSTALL_DATA} \
		${WRKSRC}/minimalist.conf-sample \
		${WRKSRC}/docs/CHANGES.txt \
		${WRKSRC}/docs/README \
		${WRKSRC}/docs/virtual-domains.txt \
		${STAGEDIR}${PREFIX}/share/minimalist/
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ/* \
		${STAGEDIR}${PREFIX}/share/minimalist/FAQ/
	${INSTALL_DATA} ${WRKSRC}/sample/lists.lst \
		${STAGEDIR}${PREFIX}/share/minimalist/lists.lst-sample
	${INSTALL_DATA} ${WRKSRC}/sample/sample/* \
		${STAGEDIR}${PREFIX}/share/minimalist/sample/

.include <bsd.port.mk>
