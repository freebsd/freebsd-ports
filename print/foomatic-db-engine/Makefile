# New ports collection makefile for:   foomatic-db-engine
# Date created:			07 July 2003
# Whom:				Martin Ranne <gasp@ridcully.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-db-engine
PORTVERSION=	20031213
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foomatic database engine

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		curl.2:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_PERL5=	yes
USE_BZIP2=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
NO_CHECKSUM=	yes	# the tarball is created on the fly from CVS
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	PERL=${PERL} LIBDIR=${PREFIX}/share/foomatic/

.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	${PORTVERSION}
CVS_SITES?=	pserver:anonymous@cvs.linuxprinting.org:/usr/local/cvs
CVS_MODULE=	foomatic-db-engine

MAN1=		foomatic-printjob.1 foomatic-ppdfile.1 foomatic-perl-data.1 \
		foomatic-configure.1 foomatic-compiledb.1 foomatic-combo-xml.1 \
		foomatic-ppd-options.1
MAN8=		foomatic-preferred-driver.8 \
		foomatic-kitload.8 foomatic-getpjloptions.8 \
		foomatic-addpjloptions.8

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
do-fetch:
	@if test ! -f ${DISTDIR}/${PKGNAME}${EXTRACT_SUFX} ; then \
		${MKDIR} ${DISTDIR}/${PKGNAME} && \
		cd ${DISTDIR}/${PKGNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
			if ${CVS_CMD} -d:$${CVS_SITE} co -D "${CVS_DATE}" ${CVS_MODULE}; \
			    then \
				cd ${DISTDIR}; \
				${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
				${ECHO_MSG} ">> \"${PKGNAME}${EXTRACT_SUFX}\"."; \
				${MV} ${PKGNAME}/${CVS_MODULE} \
					${PKGNAME}/${CVS_MODULE:H}/${PKGNAME}; \
				${TAR} -cj \
					-f ${PKGNAME}${EXTRACT_SUFX} \
					-C ${PKGNAME}/${CVS_MODULE:H} \
					${PKGNAME}; \
				exit; \
			fi \
		done; \
		${RMDIR} ${DISTDIR}/${PKGNAME}; \
		${ECHO_MSG} ">> CVS checkout failed."; \
		exit 1; \
	fi

pre-configure:
	@cd ${WRKSRC} && ./make_configure

post-build:
	@${CHMOD} +x ${WRKSRC}/mkinstalldirs

.include <bsd.port.post.mk>
