# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	0.2.0
#PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Browser based interface to Logstash and ElasticSearch

# NOTES
# - some optional gems are not listed here (jruby, etc)
# - eventmachine 1.0.1 is required in Gemfile.lock but 0.12.10 should work fine
# - same, rspec-expectations 2.11.3, rspec-mocks 2.11.3, rubygem-sinatra 1.3.3, rubygem-thin 1.5.0
RUN_DEPENDS=	rubygem-daemons>=1.1.9:${PORTSDIR}/devel/rubygem-daemons \
	rubygem-diff-lcs>=1.1.3:${PORTSDIR}/textproc/rubygem-diff-lcs \
	rubygem-eventmachine>=0.12.10:${PORTSDIR}/devel/rubygem-eventmachine \
	rubygem-fastercsv>=1.5.5:${PORTSDIR}/devel/rubygem-fastercsv \
	rubygem-json>=1.7.5:${PORTSDIR}/devel/rubygem-json \
	rubygem-rack>=1.4.5:${PORTSDIR}/www/rubygem-rack \
	rubygem-rack-protection>=1.2.0:${PORTSDIR}/www/rubygem-rack-protection \
	rubygem-rake>=10.0.3:${PORTSDIR}/devel/rubygem-rake \
	rubygem-rspec>=2.11.0:${PORTSDIR}/devel/rubygem-rspec \
	rubygem-rspec-core>=2.11.1:${PORTSDIR}/devel/rubygem-rspec-core \
	rubygem-rspec-expectations>=2.11.2:${PORTSDIR}/devel/rubygem-rspec-expectations \
	rubygem-rspec-mocks>=2.11.2:${PORTSDIR}/devel/rubygem-rspec-mocks \
	rubygem-sinatra>=1.3.2:${PORTSDIR}/www/rubygem-sinatra \
	rubygem-thin>=1.2.11:${PORTSDIR}/www/rubygem-thin \
	rubygem-tilt>=1.3.3:${PORTSDIR}/devel/rubygem-tilt \
	rubygem-tzinfo>=0.3.35:${PORTSDIR}/devel/rubygem-tzinfo \

#	rubygem-rubyzip>=0.9.9:${PORTSDIR}/FIXME/FIXME

USE_GITHUB=	yes
GH_ACCOUNT=	rashidkpc
GH_PROJECT=	Kibana
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	41a1298

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
