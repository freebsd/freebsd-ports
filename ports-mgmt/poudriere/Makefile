# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	3.0.15
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/ \
		LOCAL/bdrewery/${PORTNAME}/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}?uuid=${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	ZSH

CONFLICTS_INSTALL=	poudriere-devel

USES=		uidfix

PLIST_FILES=	etc/poudriere.conf.sample \
		bin/poudriere \
		man/man8/poudriere.8.gz \
		libexec/poudriere/cpdup \
		libexec/poudriere/dirwatch \
		libexec/poudriere/dirempty \
		libexec/poudriere/make_index \
		share/poudriere/awk/dependency_loop.awk \
		share/poudriere/awk/humanize.awk \
		share/poudriere/awk/json.awk \
		share/poudriere/awk/make_index.awk \
		share/poudriere/awk/siginfo_buildtime.awk \
		share/poudriere/html/index.html \
		share/poudriere/html/jquery-1.9.1.min.js \
		share/poudriere/html/logo.jpg \
		share/poudriere/html/poudriere.css \
		share/poudriere/html/poudriere.js \
		share/poudriere/bulk.sh \
		share/poudriere/clean.sh \
		share/poudriere/common.sh \
		share/poudriere/daemon.sh \
		share/poudriere/distclean.sh \
		share/poudriere/jail.sh \
		share/poudriere/options.sh \
		share/poudriere/ports.sh \
		share/poudriere/queue.sh \
		share/poudriere/status.sh \
		share/poudriere/testport.sh

PLIST_DIRS=	libexec/poudriere \
		share/poudriere/awk \
		share/poudriere/html \
		share/poudriere

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZSH}
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.endif

post-install:
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_poudriere
.endif

.include <bsd.port.mk>
