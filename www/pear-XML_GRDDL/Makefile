# Ports collection makefile for:  pear-XML_GRDDL
# Date created:			  23 June 2008
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML_GRDDL
PORTVERSION=	0.1.1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP library for dealing with GRDDL

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request \
		${PEARDIR}/Net/URL.php:${PORTSDIR}/net/pear-Net_URL \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log \
		${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP+=	xsl tidy

CATEGORY=	XML
FILES=		XML/GRDDL.php \
		XML/GRDDL/Driver.php XML/GRDDL/Exception.php \
		XML/GRDDL/Driver/Xsl.php

DOCS=		an-hcard-profile.php atomttl1.php \
		danc-hcal.php digg-rdfa.php \
		discover-grddl.php flickr-linkedin.php \
		grddl-base.rdf grddl-tests-normative.rdf \
		grddl-tests.rdf grddlProfileBase1.php \
		htmlbase1.php namespace-documents1.php \
		namespace-documents2.php pear-package.php \
		php-conferences.php two-transforms.php \
		xhtmlWithGrddlEnabledProfile.php \
		scripts/debug-grddl.php scripts/process-grddl.php \
		scripts/testft.py README.txt

TESTS=		44225.php ambiguous.php \
		example.php library.php \
		local.php namespaces.php \
		data/baseURI.rdf data/card-output.rdf \
		data/card5n-output.rdf data/embedded-rdf1-output.rdf \
		data/embedded-rdf2-output.rdf \
		data/embedded-rdf3-output.rdf \
		data/embedded-rdf4-output.rdf \
		data/embedded-rdf5-output.rdf \
		data/embedded-rdf6-output.rdf \
		data/embedded-rdf8-output.rdf \
		data/embedded-rdf9-output.rdf \
		data/four-transforms-output.rdf \
		data/grddlProfileWithBaseElement-output.rdf \
		data/grddlonrdf-output3.rdf \
		data/grddlonrdf-xmlmediatype-output3.rdf \
		data/hcard-output.rdf data/inline.rdf \
		data/loop-output.rdf data/loopx-output.rdf \
		data/loopx-output1.rdf data/loopx-output2.rdf \
		data/loopx-output3.rdf \
		data/multipleRepresentationsBoth-output.rdf \
		data/multipleRepresentationsHtml-output.rdf \
		data/multipleRepresentationsSvg-output.rdf \
		data/multiprofile-output.rdf data/noxinclude1.rdf \
		data/profile-with-spaces-in-rel-output.rdf \
		data/projects.rdf data/rdf_sem-output.rdf \
		data/spaces-in-rel-output.rdf \
		data/sq1-output.rdf data/sq2-output.rdf \
		data/three-transforms-output.rdf \
		data/titleauthor-output.rdf \
		data/two-transforms-output.rdf \
		data/xhtmlProfileBase1-output.rdf \
		data/xhtmlWithBaseElement-output.rdf \
		data/xhtmlWithGrddlEnabledProfile-output.rdf \
		data/xhtmlWithGrddlEnabledProfileAndADisabledInBodyTransform-output.rdf \
		data/xhtmlWithGrddlEnabledProfileAndInBodyTransform-output.rdf \
		data/xhtmlWithGrddlProfile-output.rdf \
		data/xhtmlWithGrddlTransformationInBody-output.rdf \
		data/xhtmlWithTwoTransformations-output.rdf \
		data/xhtmlWithoutBaseElement-output.rdf \
		data/xinclude1.rdf data/xmlWithBase-output.rdf \
		data/xmlWithGrddlAttribute-output.rdf \
		data/xmlWithGrddlAttributeAndNonXMLNamespaceDocument-output.rdf \
		data/xmlWithoutBase-output.rdf

DATA=		glean-profile grokAlternate grokPEAR \
		inline-rdf xml-attributes
_DATADIR=	data/grddl-library

post-extract:
		@${MV} ${WRKSRC}/README.txt ${WRKSRC}/docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
