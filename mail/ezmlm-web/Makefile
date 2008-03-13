# New ports collection makefile for:	ezmlm-web
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm-web
PORTVERSION=	3.2
CATEGORIES=	mail www
MASTER_SITES=	https://systemausfall.org/toolforge/ezmlm-web/download/ezmlm-web-3.2/

MAINTAINER=	hans@nordhaug.priv.no
COMMENT=	Manage ezmlm-idx mailing lists through the web (using CGI)

RUN_DEPENDS=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
		${SITE_PERL}/Mail/Ezmlm.pm:${PORTSDIR}/mail/p5-Mail-Ezmlm \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools

EXAMPLES=	apache.conf.dist ezmlmwebrc.dist ezmlmwebrc.minimal-dist \
		htaccess.dist multidomain.conf.dist webusers.dist
DOCS=		INSTALL README TODO UPGRADING changelog copyright

USE_GMAKE=	yes
USE_PERL5=	yes
PERL_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|local/share|share|' \
		-e 's|$$SHAREDIR/www-data|${WWWDIR}|' \
		${WRKSRC}/Makefile.PL
	${REINPLACE_CMD} -e 's|/usr/local/share/ezmlm-web/www-data/|${WWWDIR}/|' \
		${WRKSRC}/examples/apache.conf.dist
	${REINPLACE_CMD} -e 's|/etc/ezmlm|${PREFIX}/etc/ezmlm|' -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/ezmlm-web.cgi ${WRKSRC}/examples/ezmlmwebrc.dist ${WRKSRC}/suid-wrapper/index.h

.if defined(PACKAGE_BUILDING)
CONFIGURE_ENV=	BSD_BATCH_INSTALL=yes
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR} ${PREFIX}/etc/ezmlm-web
	${INSTALL_DATA} ${WRKSRC}/examples/ezmlmwebrc.dist ${PREFIX}/etc/ezmlm-web/ezmlmwebrc.sample
.for file in ${EXAMPLES}
	${INSTALL_MAN} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

MAN1=		ezmlm-web.cgi.1p

.include <bsd.port.mk>
