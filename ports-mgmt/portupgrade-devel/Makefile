# New ports collection makefile for:	portupgrade
# Date created:		18 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	portupgrade
PORTVERSION=	20011015
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.iDaemons.org/distfiles/
MASTER_SITE_SUBDIR=	knu
DISTNAME=	pkgtools-${PORTVERSION}

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	pkgtools-${PORTVERSION}.patch.gz

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse \
		${RUBY_SITEARCHLIBDIR}/fnmatch.so:${PORTSDIR}/devel/ruby-fnmatch \
		${RUBY_SITELIBDIR}/uri.rb:${PORTSDIR}/net/ruby-uri \
		${LOCALBASE}/sbin/pkg_tarup:${PORTSDIR}/misc/pkg_tarup

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	\
		${WRKSRC}/pkg_fetch \
		${WRKSRC}/pkg_glob \
		${WRKSRC}/pkgdb \
		${WRKSRC}/portcvsweb \
		${WRKSRC}/portsclean \
		${WRKSRC}/portsdb \
		${WRKSRC}/portupgrade \
		${WRKSRC}/portversion

NO_BUILD=	yes

MAN1=		pkg_deinstall.1 \
		pkg_fetch.1 \
		pkg_glob.1 \
		pkgdb.1 \
		portcvsweb.1 \
		portsclean.1 \
		portsdb.1 \
		portupgrade.1 \
		portversion.1
MLINKS=		pkgdb.1 pkg_which.1 \
		portupgrade.1 portinstall.1 \
		portsdb.1 ports_glob.1
MANCOMPRESSED=	yes

DOCS=		ChangeLog README

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

post-patch:
.for f in pkgdb.rb pkgtools.rb
	${RUBY} -i~ -pe 'sub %r:/usr/local:, "${LOCALBASE}"' ${WRKSRC}/${f}
.endfor

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/* ${PREFIX}/share/zsh/site-functions/
	${MKDIR} ${EXAMPLESDIR}/bash
	${INSTALL_DATA} ${WRKSRC}/misc/bash/* ${EXAMPLESDIR}/bash/
	${MKDIR} ${EXAMPLESDIR}/tcsh
	${INSTALL_DATA} ${WRKSRC}/misc/tcsh/* ${EXAMPLESDIR}/tcsh/
	# Remove old database
	${RM} -f /var/db/pkg/pkgdb.byfile.db
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
