;;;
;;; $Id: proofgeneral-settings.el,v 1.2 2001/09/28 18:08:05 wenzelm Exp $
;;;
;;; Options for Proof General

;; Examples for sensible settings:

;(custom-set-variables '(isar-eta-contract nil))

;(custom-set-faces
; '(proof-locked-face
;   ((((type x) (class color) (background light)) (:background "lightsteelblue2")))))

; Makarius' Poly/ML 5.0 patches
(custom-set-variables
 '(proof-shell-pre-interrupt-hook (lambda () t)))

