# New ports collection makefile for:	ezmlm-web
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm-web
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	ftp://rucus.ru.ac.za/pub/mail/ezmlm/

MAINTAINER=	guy-ezmlm@rucus.ru.ac.za
COMMENT=	CGI script that lets you manage ezmlm-idx mailing lists through the web

RUN_DEPENDS=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
		${SITE_PERL}/Mail/Ezmlm.pm:${PORTSDIR}/mail/p5-Mail-Ezmlm \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools

# Change these to suit your setup. You can do this via the environment
# CGI_BIN is the location relative to ${PREFIX} of your webservers' cgi-bin
# EZMLM_DIR is the base relative to ${PREFIX} in which ezmlm was installed
#
CGI_BIN?=	www/cgi-bin.default

USE_PERL5=	YES
PLIST_SUB=	CGI_BIN=${CGI_BIN}

EXAMPLES=	htaccess.sample webusers.sample index.c
DOCS=		CHANGES README TODO UPGRADING

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ezmlm-web index.c

post-patch:
	${REINPLACE_CMD} -e 's|/etc/ezmlm|${PREFIX}/etc/ezmlm|' \
		-e 's|/usr/local|${PREFIX}|g' -e 's|prefex|prefix|g' \
		${WRKSRC}/ezmlm-web.cgi ${WRKSRC}/ezmlmwebrc ${WRKSRC}/index.c

do-install:
	${MKDIR} ${PREFIX}/${CGI_BIN} ${PREFIX}/etc/ezmlm
	${INSTALL_SCRIPT} ${WRKSRC}/ezmlm-web.cgi ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ezmlmwebrc ${PREFIX}/etc/ezmlm/ezmlmwebrc.sample
	${INSTALL_PROGRAM} -o alias -g qmail -m 4755 ${WRKSRC}/ezmlm-web ${PREFIX}/${CGI_BIN}
	${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_MAN} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
