# New ports collection makefile for:	rabbit
# Date created:		2010-08-01
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rabbit
PORTVERSION=	0.9.2
CATEGORIES=	misc ruby
MASTER_SITES=	http://www.cozmixng.org/~kou/download/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/rabbit|}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An RD-document-based presentation application

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		rd2:${PORTSDIR}/textproc/ruby-rdtool \
		${RUBY_SITELIBDIR}/div.rb:${PORTSDIR}/www/ruby-div \
		rubygem-net-irc>=0.0.9:${PORTSDIR}/irc/rubygem-net-irc \
		ruby-pwgen:${PORTSDIR}/security/ruby-password \
		rubygem-tweetstream>=0.0.0:${PORTSDIR}/net/rubygem-tweetstream

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/gettext.rb:${PORTSDIR}/devel/ruby-gettext
PLIST_SUB+=	NLS=""
.endif

RUBY_SHEBANG_FILES=	bin/rabbirc bin/rabbit bin/rabbit-command \
			bin/rabbit-theme-manager bin/rabbiter bin/rabrick

DOCS_EN=	NEWS.en README.en
DOCS_JA=	NEWS.ja README.ja

pre-install:
	@${RM} -f ${WRKSRC}/bin/rabbit.bat
.if defined(WITHOUT_NLS)
	@${RM} -rf ${WRKSRC}/data/locale
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${DOCS_JA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/ja
.endfor
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
	${FIND} ${DATADIR} -type f | ${SORT} | ${SED} -e 's,${DATADIR},%%DATADIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/share/locale -type f -name rabbit.mo | ${SORT} | ${SED} -e 's,^${PREFIX}/,%%NLS%%,' >> pkg-plist.new
	${FIND} ${DOCSDIR} -type f | ${SORT} | ${SED} -e 's,${DOCSDIR},%%PORTDOCS%%%%DOCSDIR%%,' >> pkg-plist.new
	${FIND} ${EXAMPLESDIR} -type f | ${SORT} | ${SED} -e 's,${EXAMPLESDIR},%%PORTEXAMPLES%%%%EXAMPLESDIR%%,' >> pkg-plist.new
	${FIND} ${EXAMPLESDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${EXAMPLESDIR},%%PORTEXAMPLES%%@dirrm %%EXAMPLESDIR%%,' >> pkg-plist.new
	${FIND} ${DOCSDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${DOCSDIR},%%PORTDOCS%%@dirrm %%DOCSDIR%%,' >> pkg-plist.new
	${FIND} ${DATADIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${DATADIR},@dirrm %%DATADIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rwiki -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rabbit -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
