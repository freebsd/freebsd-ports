# New ports collection makefile for:	amavisd
# Date created:				13 May 2002
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	amavisd
PORTVERSION=	20020300
CATEGORIES=	security
MASTER_SITES=	http://www.amavis.org/dist/perl/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}

MAINTAINER=	gslin@ccca.nctu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc \
		${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha \
		${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj \
		${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar \
		${LOCALBASE}/bin/zoo:${PORTSDIR}/archivers/zoo \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Convert/UUlib.pm:${PORTSDIR}/converters/p5-Convert-UUlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools

GNU_CONFIGURE=	yes

AMAVISUSER?=	root

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc --with-amavisuser=${AMAVISUSER}

.if defined(WITH_POSTFIX)
CONFIGURE_ARGS+=	--enable-postfix
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
MTA?=		postfix
.elif defined(WITH_POSTFIX_CURRENT)
CONFIGURE_ARGS+=	--enable-postfix
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
MTA?=		postfix
.elif defined(WITH_QMAIL)
CONFIGURE_ARGS+=	--enable-qmail
RUN_DEPENDS+=	${LOCALBASE}/bin/qmail-smtpd:${PORTSDIR}/mail/qmail
MTA?=		qmail
.else
CONFIGURE_ARGS+=	--enable-sendmail
MTA?=		sendmail
.endif

post-patch:
	@${SED} "s,%%AMAVISUSER%%,${AMAVISUSER}," ${FILESDIR}/amavisd.sh.sample > ${WRKSRC}/amavisd.sh.sample

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd.sh.sample ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in FAQ INSTALL README README.exim README.milter README.postfix README.qmail README.scanners README.sendmail doc/amavis.html doc/amavis.m4 doc/amavis.png doc/amavis.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Please read ${DOCSDIR}/README.${MTA}"
.endif

.include <bsd.port.mk>
