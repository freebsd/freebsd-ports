# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	3.0.99.20131028
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/ \
		LOCAL/bdrewery/${PORTNAME}/
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${FSL_CHKIN}

# Also maintained by bdrewery@FreeBSD.org
MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

FSL_CHKIN=	6da5271386

OPTIONS_DEFINE=	ZSH

CONFLICTS_INSTALL=	poudriere-[0-9]*

USES=		uidfix

PLIST_FILES=	etc/poudriere.conf.sample \
		etc/poudriere.d/hooks/bulk.sh.sample \
		etc/poudriere.d/hooks/pkgbuild.sh.sample \
		etc/rc.d/poudriere \
		bin/poudriere \
		man/man8/poudriere.8.gz \
		libexec/poudriere/cpdup \
		libexec/poudriere/dirwatch \
		libexec/poudriere/dirempty \
		libexec/poudriere/make_index \
		share/poudriere/awk/dependency_loop.awk \
		share/poudriere/awk/humanize.awk \
		share/poudriere/awk/json.awk \
		share/poudriere/awk/siginfo_buildtime.awk \
		share/poudriere/html/index.html \
		share/poudriere/html/assets/bootstrap/css/bootstrap-responsive.min.css \
		share/poudriere/html/assets/bootstrap/css/bootstrap.min.css \
		share/poudriere/html/assets/bootstrap/img/glyphicons-halflings-white.png \
		share/poudriere/html/assets/bootstrap/img/glyphicons-halflings.png \
		share/poudriere/html/assets/bootstrap/js/bootstrap.min.js \
		share/poudriere/html/assets/dataTables/css/jquery.dataTables.css \
		share/poudriere/html/assets/dataTables/images/back_disabled.png \
		share/poudriere/html/assets/dataTables/images/back_enabled.png \
		share/poudriere/html/assets/dataTables/images/back_enabled_hover.png \
		share/poudriere/html/assets/dataTables/images/forward_disabled.png \
		share/poudriere/html/assets/dataTables/images/forward_enabled.png \
		share/poudriere/html/assets/dataTables/images/forward_enabled_hover.png \
		share/poudriere/html/assets/dataTables/images/sort_asc.png \
		share/poudriere/html/assets/dataTables/images/sort_asc_disabled.png \
		share/poudriere/html/assets/dataTables/images/sort_both.png \
		share/poudriere/html/assets/dataTables/images/sort_desc.png \
		share/poudriere/html/assets/dataTables/images/sort_desc_disabled.png \
		share/poudriere/html/assets/dataTables/js/jquery.dataTables.min.js \
		share/poudriere/html/assets/jquery-1.9.1.min.js \
		share/poudriere/html/assets/logo.jpg \
		share/poudriere/html/assets/poudriere.css \
		share/poudriere/html/assets/poudriere.js \
		share/poudriere/bulk.sh \
		share/poudriere/clean.sh \
		share/poudriere/common.sh \
		share/poudriere/common.sh.dragonfly \
		share/poudriere/common.sh.freebsd \
		share/poudriere/daemon.sh \
		share/poudriere/distclean.sh \
		share/poudriere/jail.sh \
		share/poudriere/options.sh \
		share/poudriere/pkgclean.sh \
		share/poudriere/ports.sh \
		share/poudriere/processonelog.sh \
		share/poudriere/queue.sh \
		share/poudriere/status.sh \
		share/poudriere/testport.sh

PLIST_DIRS=	libexec/poudriere \
		etc/poudriere.d/hooks \
		etc/poudriere.d \
		share/poudriere/awk \
		share/poudriere/html/assets/bootstrap/css \
		share/poudriere/html/assets/bootstrap/img \
		share/poudriere/html/assets/bootstrap/js \
		share/poudriere/html/assets/bootstrap \
		share/poudriere/html/assets/dataTables/css \
		share/poudriere/html/assets/dataTables/images \
		share/poudriere/html/assets/dataTables/js \
		share/poudriere/html/assets/dataTables \
		share/poudriere/html/assets \
		share/poudriere/html \
		share/poudriere

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZSH}
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.else
MAKE_ENV+=	NO_ZSH=yes
.endif

.include <bsd.port.mk>
