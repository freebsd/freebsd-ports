# New ports collection makefile for:	p5-Mail-CClient
# Date created:				01 July 2000
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=		CClient
PORTVERSION=		1.12
PORTREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-
DISTNAME=		Mail-Cclient-${PORTVERSION}

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Perl interface to the c-client mailbox API

LIB_DEPENDS=		c-client4.9:${PORTSDIR}/mail/cclient

PERL_CONFIGURE=		yes
CONFIGURE_ARGS=		--cclient_dir=${LOCALBASE} \
		 	--with-shared_cclient \
			--with-pam \
			--with-cclient-includes=${LOCALBASE}/include/c-client

MAN3=			Mail::Cclient.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes FAQ README TODO
EXAMPLES=	copy.txt \
		fetch_body.pl \
		fetch_structure.pl \
		imap.txt \
		list_mailboxs.pl \
		mime.txt \
		rfc822_date.pl \
		rfc822_output.txt \
		rfc822_parse_adrlist.pl \
		rfc822_write_address.pl \
		search.txt \
		search_msg.txt \
		smtp_mail.pl \
		smtp_mail_append.txt \
		smtp_mail_mpart.pl \
		sort.txt \
		struct.txt \
		summ.txt \
		thread.txt \
		thread_test.pl \
		utf8_mime2text.pl

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Documentation installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's/-lc-client/-lc-client4/g;' \
		     -e 's/"-lc"/"-L\$$CCLIENT_DIR\/lib "/g;' \
		     -e 's/ -lpam_misc//g;' \
		 ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
