# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.scarlet.be/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://ftp.planetmirror.com/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		http://www.mehok.uni-miskolc.hu/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://ftp.heanet.ie/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://opera.nsc.no/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		http://ftp.task.gda.pl/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://ftp.idilis.ro/mirrors/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		http://www.fastmirrors.org/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		http://ftp.sunet.se/pub/www/clients/Opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://mirror.switch.ch/mirror/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		http://ftp.ankara.edu.tr/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		ftp://files.downloadthat.com/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/&,} \
		ftp://ftp.opera.com/pub/opera/unix/freebsd/${OPERA_VER:S/.//}/${OPERA_REL}/en/static/
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_DATE}.1-static-qt.i386.freebsd-en

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

OPERA_VER=	7.53
OPERA_REL=	final
OPERA_DATE=	20040716

DATADIR=	${PREFIX}/share/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

.ifndef(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.15:${PORTSDIR}/textproc/aspell
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

.if ${HAVE_GNOME:Mgnomehier}!=""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if exists(${LOCALBASE}/bin/kde-config)
PLIST_SUB+=	KDE=""
.else
PLIST_SUB+=	KDE="@comment "
.endif

pre-everything::
.if !defined(WITHOUT_ASPELL)
	@${ECHO_CMD} '===> The following options are available for this port:'
	@${ECHO_CMD} '===>'
	@${ECHO_CMD} '===> Define WITHOUT_ASPELL to not install aspell.'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/install.sh ${WRKSRC}/ini/pluginpath.ini \
			${WRKSRC}/ini/spellcheck.ini ${WRKSRC}/config/opera6rc
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
