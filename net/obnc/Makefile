# New ports collection makefile for:	obnc
# Date created:			3 July 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	obnc
PORTVERSION=	20020222
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dd@FreeBSD.org
COMMENT=	OpenBSD's netcat: cleaner code, familiar interface, IPv6 support

MANSECTS=	1
MAN1=		nc.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/nc

CFLAGS+=	-DIPSEC
MAKE_ENV=	LDADD="${LDADD} -lipsec"

# MAN page COMPression SUFFIX
.if !defined(NOMANCOMPRESS)
MANCOMPSUFFIX=	.gz
.else
MANCOMPSUFFIX=
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nc ${PREFIX}/bin/nc
.for __s in ${MANSECTS}
.for __m in ${MAN${__s}:S/$/${MANCOMPSUFFIX}/}
	@${INSTALL_MAN} ${WRKSRC}/${__m} ${PREFIX}/man/man${__s}/${__m}
.endfor
.endfor

#
# Ports build/install stuff stops here.  Tarball creation stuff begins here.
#
.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	Fri Feb 22 00:09:41 UTC 2002
CVS_SITES?=	anoncvs@anoncvs3.usa.openbsd.org:/cvs \
		anoncvs@anoncvs1.ca.openbsd.org:/cvs
CVS_MODULE=	src/usr.bin/nc

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
tarball:
	@${MKDIR} ${DISTDIR}/${PKGNAME} && \
	cd ${DISTDIR}/${PKGNAME}; \
	for CVS_SITE in ${CVS_SITES}; do \
		${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
		if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
		    ${CVS_MODULE}; then \
			cd ${DISTDIR}; \
			${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
			${ECHO_MSG} ">> \"${PKGNAME}.tar.gz\"."; \
			${MV} ${PKGNAME}/${CVS_MODULE} \
				${PKGNAME}/${CVS_MODULE:H}/${PKGNAME}; \
			${TAR} -cz \
				-X ${FILESDIR}/tarignore \
				-f ${PKGNAME}.tar.gz \
				-C ${PKGNAME}/${CVS_MODULE:H} \
				${PKGNAME}; \
			exit; \
		fi \
	done; \
	${RMDIR} ${DISTDIR}/${PKGNAME}; \
	${ECHO_MSG} ">> CVS checkout failed."; \
	exit 1;

.include <bsd.port.post.mk>
