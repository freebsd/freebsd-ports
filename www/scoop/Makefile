# New ports collection makefile for:	scoop
# Date created:				11 November 2002
# Whom:					patrick
#
# $FreeBSD$
#

PORTNAME=	scoop
PORTVERSION=	0.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	patrick@ginx.com
COMMENT=	A "collaborative media application."

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton \
		${SITE_PERL}/Crypt/UnixCrypt.pm:${PORTSDIR}/security/p5-Crypt-UnixCrypt \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/String/Random.pm:${PORTSDIR}/devel/p5-String-Random \
		${SITE_PERL}/Time/Timezone.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS

NO_BUILD=yes

do-install:
	@${MKDIR} ${PREFIX}/www/scoop
	@${CP} -Rp ${WRKSRC}/ ${PREFIX}/www/scoop

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
