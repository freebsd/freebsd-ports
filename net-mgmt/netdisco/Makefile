# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	netdisco
DISTVERSION=	2.039033
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OLIVER
DISTNAME=	App-Netdisco-${PORTVERSION}

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Network discovery/management tool with web console

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg \
		p5-Net-SNMP>=6.0.1:net-mgmt/p5-Net-SNMP \
		p5-Algorithm-Cron>=0.07:devel/p5-Algorithm-Cron \
		p5-aliased>=0:devel/p5-aliased \
		p5-AnyEvent>=7.05:devel/p5-AnyEvent \
		p5-AnyEvent-DNS-EtcHosts>=0.0103:dns/p5-AnyEvent-DNS-EtcHosts \
		p5-App-cpanminus>=1.6108:devel/p5-App-cpanminus \
		p5-App-local-lib-helper>=0.07:devel/p5-App-local-lib-helper \
		p5-Archive-Extract>=0:archivers/p5-Archive-Extract \
		p5-CGI-Expand>=2.05:www/p5-CGI-Expand \
		p5-Data-Printer>=0:devel/p5-Data-Printer \
		p5-DBIx-Class-Helpers>=2.033004:databases/p5-DBIx-Class-Helpers \
		p5-Daemon-Control>=0.001.005:devel/p5-Daemon-Control \
		p5-Dancer>=1.3132:www/p5-Dancer \
		p5-Dancer-Plugin-DBIC>=0.2001:databases/p5-Dancer-Plugin-DBIC \
		p5-Dancer-Plugin-Auth-Extensible>=0.30:security/p5-Dancer-Plugin-Auth-Extensible \
		p5-Dancer-Plugin-Passphrase>=2.0.1:security/p5-Dancer-Plugin-Passphrase \
		p5-Dancer-Session-Cookie>=0.27:www/p5-Dancer-Session-Cookie \
		p5-Env-Path>=0:devel/p5-Env-Path \
		p5-File-ShareDir>=1.03:devel/p5-File-ShareDir \
		p5-File-Slurp>=9999.19:devel/p5-File-Slurp \
		p5-Guard>=1.022:devel/p5-Guard \
		p5-Graph>=0:math/p5-Graph \
		p5-GraphViz>=0:graphics/p5-GraphViz \
		p5-HTML-Parser>=3.70:www/p5-HTML-Parser \
		p5-HTTP-Tiny>=0.029:www/p5-HTTP-Tiny \
		p5-JSON>=0:converters/p5-JSON \
		p5-List-MoreUtils>=0.33:lang/p5-List-MoreUtils \
		p5-Log-Message-Simple>=0:devel/p5-Log-Message-Simple \
		p5-Module-Find>=0.12:devel/p5-Module-Find \
		p5-Module-Load>=0.32:devel/p5-Module-Load \
		p5-Moo>=1.001000:devel/p5-Moo \
		p5-MCE>=1.515:devel/p5-MCE \
		p5-MIME-Base64>=0:converters/p5-MIME-Base64 \
		p5-Net-DNS>=0.72:dns/p5-Net-DNS \
		p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH \
		p5-NetAddr-MAC>=0:net/p5-NetAddr-MAC \
		p5-NetAddr-IP>=4.068:net-mgmt/p5-NetAddr-IP \
		p5-Path-Class>=0.32:devel/p5-Path-Class \
		p5-Plack>=1.0023:www/p5-Plack \
		p5-Plack-Middleware-Debug>=0:www/p5-Plack-Middleware-Debug \
		p5-Plack-Middleware-Expires>=0.03:www/p5-Plack-Middleware-Expires \
		p5-Plack-Middleware-ReverseProxy>=0.15:www/p5-Plack-Middleware-ReverseProxy \
		p5-Role-Tiny>=1.002005:devel/p5-Role-Tiny \
		p5-Sereal>=0:converters/p5-Sereal \
		p5-Socket6>=0.23:net/p5-Socket6 \
		p5-Starman>=0.4008:www/p5-Starman \
		p5-Sys-SigAction>=0:devel/p5-Sys-SigAction \
		p5-SNMP-Info>=3.54:net-mgmt/p5-SNMP-Info \
		p5-SQL-Translator>=0.11018:databases/p5-SQL-Translator \
		p5-Template-Toolkit>=2.24:www/p5-Template-Toolkit \
		p5-Template-Plugin-CSV>=0.04:textproc/p5-Template-Plugin-CSV \
		p5-Template-Plugin-Number-Format>=1.02:www/p5-Template-Plugin-Number-Format \
		p5-Term-UI>=0:devel/p5-Term-UI \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Twiggy>=0:www/p5-Twiggy \
		p5-URI>=0:net/p5-URI \
		p5-URL-Encode>=0.01:www/p5-URL-Encode \
		p5-YAML>=0.84:textproc/p5-YAML \
		p5-YAML-LibYAML>=0.41:textproc/p5-YAML-LibYAML \
		p5-IO-Socket-SSL>=2.048:security/p5-IO-Socket-SSL \
		p5-File-Slurper>=0:devel/p5-File-Slurper

RUN_DEPENDS:=	${BUILD_DEPENDS}

USERS=		netdisco
GROUPS=		netdisco

SUB_FILES=	pkg-message netdiscologs.conf.sample localenv
SUB_LIST=	SITE_PERL=${STAGEDIR}${PREFIX}/${SITE_PERL_REL} \
		NETDISCO_USER=${USERS} \
		NETDISCO_GROUP=${GROUPS} \
		ETCDIR=${ETCDIR} \
		ETCDIR_REL=${ETCDIR_REL}
PLIST_SUB+=	ETCDIR=${ETCDIR}

USES=		perl5 pgsql
USE_PERL5=	modbuild
USE_RC_SUBR=	netdisco
NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/perl5/bin
	${INSTALL_SCRIPT} ${WRKDIR}/localenv ${STAGEDIR}${ETCDIR}/perl5/bin
	${INSTALL_DATA} ${WRKDIR}/netdiscologs.conf.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/environments
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/auto/share/dist/App-Netdisco/environments/deployment.yml \
		${STAGEDIR}${ETCDIR}/environments/deployment.yml.sample

.include <bsd.port.mk>
