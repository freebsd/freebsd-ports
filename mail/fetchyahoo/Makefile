# New ports collection makefile for:	fetchyahoo
# Date created:				2003-09-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fetchyahoo
PORTVERSION=	2.5.5
CATEGORIES=	mail
MASTER_SITES=	http://fetchyahoo.sourceforge.net/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Download e-mail from a Yahoo account to a Berkeley mailbox

RUN_DEPENDS=	\
	encode-base64:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/IO/Lines.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net \
	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
	${SITE_PERL}/${PERL_ARCH}/HTML/Filter.pm:${PORTSDIR}/www/p5-HTML-Parser\
	${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww

DOCS=		COPYING ChangeLog Credits INSTALL TODO index.html
MAN1=		fetchyahoo.1
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_PERL5=	yes

.include <bsd.port.pre.mk>

do-patch:
# Use an RFC 2606 domain:  myhost.com is registered.
	${PERL} -pi -e "s:myhost.com:example:g" ${WRKSRC}/fetchyahoorc

pre-install:
	${ECHO_CMD} bin/fetchyahoo > ${PLIST}
.if !defined(NOPORTDOCS)
	${ECHO_CMD} share/examples/fetchyahoo/fetchyahoorc >> ${PLIST}
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/fetchyahoo/${ii} >> ${PLIST}
.endfor
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fetchyahoo.pl ${PREFIX}/bin/fetchyahoo
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fetchyahoorc ${EXAMPLESDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
