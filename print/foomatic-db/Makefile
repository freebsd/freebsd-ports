# New ports collection makefile for:	foomatic-db
# Date created:			01 March 2003
# Whom:				Dima Dorfman <dima@unixfreak.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-db
PORTVERSION=	20060506
CATEGORIES=	print
MASTER_SITES=	# custom fetch
NO_CHECKSUM=	${DISTFILES}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Foomatic database

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		curl.3:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_PERL5=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:259

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	${PORTVERSION}
CVS_SITES?=	pserver:anonymous@cvs.linuxprinting.org:/var/lib/cvs
CVS_BRANCH=	foomatic-3_0-branch	# STABLE
CVS_MODULE=	foomatic-db

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
do-fetch:
	@if test ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ; then \
		${MKDIR} ${DISTDIR}/${DISTNAME} && \
		cd ${DISTDIR}/${DISTNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
			if ${CVS_CMD} -d:$${CVS_SITE} co -D "${CVS_DATE}" -r ${CVS_BRANCH} ${CVS_MODULE}; \
			    then \
				cd ${DISTDIR}; \
				${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
				${ECHO_MSG} ">> \"${DISTNAME}${EXTRACT_SUFX}\"."; \
				${MV} ${DISTNAME}/${CVS_MODULE} \
					${DISTNAME}/${CVS_MODULE:H}/${DISTNAME}; \
				${TAR} -cj \
					-X ${FILESDIR}/tarignore \
					-f ${DISTNAME}${EXTRACT_SUFX} \
					-C ${DISTNAME}/${CVS_MODULE:H} \
					${DISTNAME}; \
				exit; \
			fi \
		done; \
		${RMDIR} ${DISTDIR}/${DISTNAME}; \
		${ECHO_MSG} ">> CVS checkout failed."; \
		exit 1; \
	fi

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

.include <bsd.port.post.mk>
