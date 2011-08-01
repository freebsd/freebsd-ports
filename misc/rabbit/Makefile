# New ports collection makefile for:	rabbit
# Date created:		2010-08-01
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rabbit
PORTVERSION=	0.9.3
CATEGORIES=	misc ruby
MASTER_SITES=	http://rabbit-shockers.org/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/rabbit|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An RD-document-based presentation application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/rsvg2.so:${PORTSDIR}/graphics/ruby-rsvg2 \
		${RUBY_SITEARCHLIBDIR}/poppler.so:${PORTSDIR}/x11-toolkits/ruby-poppler \
		rd2:${PORTSDIR}/textproc/ruby-rdtool \
		${RUBY_SITELIBDIR}/div.rb:${PORTSDIR}/www/ruby-div \
		rubygem-net-irc>=0.0.9:${PORTSDIR}/irc/rubygem-net-irc \
		ruby-pwgen:${PORTSDIR}/security/ruby-password \
		rubygem-twitter-stream>=0:${PORTSDIR}/net/rubygem-twitter-stream \
		rubygem-twitter_oauth>=0:${PORTSDIR}/security/rubygem-twitter_oauth \
		hikidoc:${PORTSDIR}/textproc/ruby-hikidoc

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	build
RUN_DEPENDS+=	rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext
PLIST_SUB+=	NLS=""
.endif

RUBY_SHEBANG_FILES=	update-mo.rb update-po.rb \
			bin/rabbirc bin/rabbit bin/rabbit-command \
			bin/rabbit-theme-manager bin/rabbiter bin/rabrick \
			bin/rabwii

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

.if !defined(WITHOUT_NLS)
pre-build:
	@cd ${BUILD_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} update-mo.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/sample && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${CP} /dev/null pkg-plist.new
.for f in ${RUBY_SHEBANG_FILES}
	${ECHO} ${f} >> pkg-plist.new
.endfor
	${FIND} ${RUBY_SITELIBDIR}/rabbit -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rwiki -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/share/locale -type f -name rabbit.mo | ${SORT} | ${SED} -e 's,^${PREFIX}/,%%NLS%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rwiki -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rabbit -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
