(load "pdf-tools-loaddefs.el")
(autoload 'pdf-view-mode "pdf-tools")
(add-to-list 'auto-mode-alist '("\\.[pP][dD][fF]\\'" . pdf-view-mode))
(add-hook 'pdf-view-mode-hook 'pdf-tools-enable-minor-modes)
