# Created by: Tomoyuki Sakurai <cherry@trombik.mine.nu>
# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	3.7.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/
PKGNAMESUFFIX=	37

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20

BUILD_DEPENDS=	rubygem-facter>=0:sysutils/rubygem-facter \
		rubygem-hiera1>=0:sysutils/rubygem-hiera1
RUN_DEPENDS=	rubygem-facter>=0:sysutils/rubygem-facter \
		rubygem-ruby-augeas>=0:textproc/rubygem-ruby-augeas \
		rubygem-hiera1>=0:sysutils/rubygem-hiera1

USES=		cpe
CPE_VENDOR=	puppetlabs
CONFLICTS_INSTALL=	puppet38-* puppet4-*
NO_BUILD=	yes
USE_RUBY=	yes
USE_RC_SUBR=	puppet puppetmaster
PORTDOCS=	LICENSE README.md
PORTEXAMPLES=	*
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message
SUB_LIST=	RUBY=${RUBY}

OPTIONS_DEFINE=		DOCS EXAMPLES

.include <bsd.port.pre.mk>

# puppet 4.x should support ruby 2.2.x
.if ${RUBY_VER} >= 2.2
BROKEN=		Does not work with Ruby 2.2
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/puppet|${ETCDIR}|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/defaults.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|/var/lib/puppet|/var/puppet|" \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$vardir/run|/var/run/puppet|" \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${REINPLACE_CMD} -e "s|\$$confdir/ssl|/var/puppet/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/ext/rack/config.ru

do-install:
	${SETENV} ${MAKE_ENV}${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/manifests ${STAGEDIR}${ETCDIR}/modules \
		${STAGEDIR}/var/puppet ${STAGEDIR}${WWWDIR} \
		${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf-dist
	${RUBY} -I ${STAGEDIR}/${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet agent --genconfig \
		--confdir=${ETCDIR} \
		--rundir=/var/run/puppet \
		--vardir=/var/puppet \
		--logdir=/var/log/puppet \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist
	${INSTALL_DATA} ${WRKSRC}/ext/rack/config.ru ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ext/rack/example-passenger-vhost.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
