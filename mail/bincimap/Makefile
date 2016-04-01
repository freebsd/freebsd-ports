# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	bincimap
PORTVERSION=	1.2.13
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight IMAP server for Maildir

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	checkpassword-pam:security/checkpassword-pam \
		tcpserver:sysutils/ucspi-tcp

USE_RC_SUBR=	bincimapd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

DOCS=		AUTHORS ChangeLog README doc/bincimap* \
		doc/manual/bincimap-manual.ps
EXAMPLES=	conf/bincimap.conf conf/checkpassword.pl conf/toimapdir \
		conf/tomaildir++ conf/xinetd-bincimap conf/xinetd-bincimaps
CONTRIB=	contrib/README contrib/authenticators/bincimap-auth-teapop.sh

OPTIONS_DEFINE=	DOCS EXAMPLES OPENSSL
OPTIONS_DEFAULT=	OPENSSL

OPENSSL_USE=	OPENSSL=yes
OPENSSL_CONFIGURE_OFF=	--without-ssl

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/bincimap.conf \
		${STAGEDIR}${ETCDIR}/bincimap.conf.sample
	cd ${WRKSRC}/man && ${INSTALL_MAN} bincimap-up.1 bincimapd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/bincimap.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${CONTRIB} \
		${STAGEDIR}${EXAMPLESDIR}/contrib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
