;;; ukr-koi8u.el --- Support for Cyrillic -*- coding: iso-2022-7bit; -*-

;;; Code:

;; KOI8-U staff

(eval-and-compile

(defvar cyrillic-koi8-u-decode-table
  [
   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
   16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
   32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47
   48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
   64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79
   80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95
   96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111
   112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127
   128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143
   144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159
   32  32  32  ?,Lq(B  ?,Lt(B  32  ?,Lv(B  ?,Lw(B  32  32  32  32  32  ?,Ls(B  32  32
   32  32  32  ?,L!(B  ?,L$(B  32  ?,L&(B  ?,L'(B  32  32  32  32  32  ?,L#(B  32  32
   ?,Ln(B  ?,LP(B  ?,LQ(B  ?,Lf(B  ?,LT(B  ?,LU(B  ?,Ld(B  ?,LS(B  ?,Le(B  ?,LX(B  ?,LY(B  ?,LZ(B  ?,L[(B  ?,L\(B  ?,L](B  ?,L^(B 
   ?,L_(B  ?,Lo(B  ?,L`(B  ?,La(B  ?,Lb(B  ?,Lc(B  ?,LV(B  ?,LR(B  ?,Ll(B  ?,Lk(B  ?,LW(B  ?,Lh(B  ?,Lm(B  ?,Li(B  ?,Lg(B  ?,Lj(B 
   ?,LN(B  ?,L0(B  ?,L1(B  ?,LF(B  ?,L4(B  ?,L5(B  ?,LD(B  ?,L3(B  ?,LE(B  ?,L8(B  ?,L9(B  ?,L:(B  ?,L;(B  ?,L<(B  ?,L=(B  ?,L>(B 
   ?,L?(B  ?,LO(B  ?,L@(B  ?,LA(B  ?,LB(B  ?,LC(B  ?,L6(B  ?,L2(B  ?,LL(B  ?,LK(B  ?,L7(B  ?,LH(B  ?,LM(B  ?,LI(B  ?,LG(B  ?,LJ(B ]
  "Cyrillic KOI8-U decoding table.")

(defvar cyrillic-koi8-u-encode-table
  (let ((table (make-vector 256 32))
	(i 0))
    (while (< i 256)
      (let* ((ch (aref cyrillic-koi8-u-decode-table i))
	     (split (split-char ch)))
	(cond ((eq (car split) 'cyrillic-iso8859-5)
	       (aset table (logior (nth 1 split) 128) i)
	       )
	      ((eq ch 32))
	      ((eq (car split) 'ascii)
	       (aset table ch i)
	       )))
      (setq i (1+ i)))
    table)
  "Cyrillic KOI8-U encoding table.")

(define-ccl-program ccl-decode-koi8-u
  `(3
    ((read r0)
     (loop
      (write-read-repeat r0 ,cyrillic-koi8-u-decode-table))))
  "CCL program to decode KOI8.")

(define-ccl-program ccl-encode-koi8-u
  `(1
    ((read r0)
     (loop
      (if (r0 != ,(charset-id 'cyrillic-iso8859-5))
	  (write-read-repeat r0)
	((read r0)
	 (write-read-repeat r0 , cyrillic-koi8-u-encode-table))))))
  "CCL program to encode KOI8.")

(make-coding-system
 'koi8-u 'ccl
 "KOI8-U 8-bit encoding for Cyrillic."
 '(decode ccl-decode-koi8-u
   encode ccl-encode-koi8-u
   mnemonic "KOI8"))

;; `iso-8-1' is not correct, but XEmacs doesn't have a `ccl' category
(coding-system-put 'koi8-u 'category 'iso-8-1)

;; (define-ccl-program ccl-encode-koi8-u-font
;;    `(0
;;      ((r1 |= 128)
;;       (r1 = r1 ,cyrillic-koi8-u-encode-table)))
;;    "CCL program to encode Cyrillic chars to koi8-u font.")

;; (setq font-ccl-encoder-alist
;;       (cons '("koi8-u" . ccl-encode-koi8-u-font) font-ccl-encoder-alist))

(defvar cyrillic-koi8-u-to-external-code-table
  (let ((table (make-char-table 'generic))
	(i 0)
	(len (length cyrillic-koi8-u-decode-table)))
    (while (< i len)
      (let ((ch (aref cyrillic-koi8-u-decode-table i)))
	(if (characterp ch)
	    (put-char-table ch i table)))
      (incf i)))
  "Table to convert from characters to their Koi8-U code.")

(set-language-info-alist
 "Cyrillic-KOI8-U" '((charset cyrillic-iso8859-5)
		   (coding-system koi8-u)
		   (coding-priority koi8-u)
		   (input-method . "cyrillic-yawerty")
		   (features cyril-util)
		   (tutorial . "TUTORIAL.ru")
		   (sample-text . "Russian (,L@caaZXY(B)	,L7T`PRabRcYbU(B!")
		   (documentation . "Support for Cyrillic KOI8-U."))
 '("Cyrillic"))
 
 )


(provide 'ukr-koi8u)
